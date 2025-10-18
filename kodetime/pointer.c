#include "stdio.h"

typedef struct
{
    const char *name;
    int height;
    int weight;
    int growth_height_to_weight_ratio;
} Animal;

typedef struct
{
    int nutrition_value;
} Food;

void feed_animal(Animal *animal, Food *food)
{
    animal->height += food->nutrition_value * animal->growth_height_to_weight_ratio;
    animal->weight += food->nutrition_value;
}

void print_animal(Animal *animal)
{
    printf("%s weights: %d tonnes and is %d meter tall\n", animal->name, animal->weight, animal->height);
}

int main()
{
    // create Food structs, examples illustrate different ways to initialize this
    Food food_dangerous;                       // WARNING not guarenteed to be zero-initilized
    Food leaves = {1};                         // explictly initilized to 1
    Food power_feed = {.nutrition_value = 10}; // nutrition_value explictly initilized to 10

    // initilize animal structs
    Animal elephant = {"elephant", 1, 2, 1};
    Animal giraffe = {.name = "giraffe", .height = 2, .weight = 1, .growth_height_to_weight_ratio = 2};

    // the feed_animal function accepts pointer types, we get these by 'deferencing' the instances of struct using '&'
    print_animal(&elephant);
    feed_animal(&elephant, &leaves);
    print_animal(&elephant);

    print_animal(&giraffe);
    feed_animal(&giraffe, &power_feed);
    print_animal(&giraffe);
}