//System ewidencji wsczepow w grze Cyberpunk 2077 xd, zrobione w ramach nauki do labow C ze struktur

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SN_LENGTH 6

typedef struct Cyberware{
    char serial_number[MAX_SN_LENGTH + 1];
    char *producer;
    unsigned short capacity_cost;
    double base_stats[3];
} Cyberware;

void print_cyberware(Cyberware item){
    
    printf("[%s] Producent: %s, Koszt: %d, Staty: %.1f %.1f %.1f\n", 
        item.serial_number,
        (item.producer ? item.producer : "Unknown Corp"),
        item.capacity_cost,
        item.base_stats[0], item.base_stats[1], item.base_stats[2]);
}

void set_model_sn(Cyberware *item, const char *sn){
    
    if(!item || !sn) return;
    strncpy(item->serial_number, sn, MAX_SN_LENGTH);
    item->serial_number[MAX_SN_LENGTH] = '\0';
}

void set_producer(Cyberware *item, const char *producer_name){
    
    if(!item) return;
    free(item->producer);
    
    if(producer_name){
        item->producer = (char *)malloc(strlen(producer_name)+1);
        if(item->producer){
            strcpy(item->producer, producer_name);
        }
    } else {
        item->producer = NULL;
    }
}

void set_stats(Cyberware *item, const double *stats_array){
    if(!item || !stats_array) return;
    memcpy(item->base_stats, stats_array, 3 * sizeof(double));
}

void set_capacity(Cyberware *item, unsigned int capacity){
    if(item) item->capacity_cost = (unsigned short)capacity;
}

Cyberware *clone_cyberware(const Cyberware *original){
    if(!original) return NULL;
    
    Cyberware *new_item = (Cyberware *)malloc(sizeof(Cyberware));
    if(!new_item) return NULL;
    new_item->producer = NULL;
    
    set_model_sn(new_item, original->serial_number);
    set_producer(new_item, original->producer);
    set_capacity(new_item, original->capacity_cost);
    set_stats(new_item, original->base_stats);

    return new_item;
}

void uninstall_cyberware(Cyberware *item){
    if(item){
        free(item->producer);
        item->producer = NULL;
    }
}

int main() {
    printf("--- SYSTEM OPERACYJNY RIPPERDOCA  ---\n\n");

    Cyberware mantis_blades = { .producer = NULL }; 
    set_model_sn(&mantis_blades, "MN-T1");
    set_producer(&mantis_blades, "Arasaka Corp");
    set_capacity(&mantis_blades, 20);
    double mantis_stats[] = {15.0, 10.0, 0.0}; // Pancerz, Kryt, Cooldown
    set_stats(&mantis_blades, mantis_stats);

    printf("1. Zainstalowano oryginal:\n");
    print_cyberware(mantis_blades);

    printf("\n2. Klonowanie wszczepu dla innego klienta...\n");
    Cyberware *cloned_blades = clone_cyberware(&mantis_blades);
    
    if (cloned_blades) {
      
        set_producer(cloned_blades, "Dynalar (Budget Version)");
        set_capacity(cloned_blades, 25); 

        printf("Klon (zmodyfikowany):\n");
        print_cyberware(*cloned_blades);
        printf("Oryginal: \n");
        print_cyberware(mantis_blades);
    }

  
    printf("\n3. Testowanie wszczepu bez papierow (Black Market):\n");
    Cyberware sandy;
    sandy.producer = NULL; 
    set_model_sn(&sandy, "QIAN-T");
    set_producer(&sandy, NULL); // Unknown Corp
    set_capacity(&sandy, 35);
    double sandy_stats[] = {0.0, 25.0, 60.0};
    set_stats(&sandy, sandy_stats);
    print_cyberware(sandy);

    
    uninstall_cyberware(&mantis_blades);
    uninstall_cyberware(&sandy);
    
    if (cloned_blades) {
        uninstall_cyberware(cloned_blades); 
        free(cloned_blades);               
    }

    printf("\n--- Diagnostyka zakonczona. ---\n");

    return 0;
}
