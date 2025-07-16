#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // usleep

#define NUM_TASKS 3
#define TICKS_PER_TASK 2  // time slice per task in ticks

typedef void (*TaskFunction)();

typedef struct {
    TaskFunction func;
    const char *name;
    int priority;          // 1 (highest) to N (lowest)
} Task;

// Task functions
void task1() {
    printf("   [Task 1] Processing data...\n");
}

void task2() {
    printf("   [Task 2] Reading sensors...\n");
}

void task3() {
    printf("   [Task 3] Sending data...\n");
}

// Global task list
Task tasks[NUM_TASKS];

// Initialize tasks
void init_tasks() {
    tasks[0].func = task1;
    tasks[0].name = "Task 1";
    tasks[0].priority = 2;

    tasks[1].func = task2;
    tasks[1].name = "Task 2";
    tasks[1].priority = 1;

    tasks[2].func = task3;
    tasks[2].name = "Task 3";
    tasks[2].priority = 3;
}

// Simulate a single tick of a task
void run_task(Task *t) {
    t->func();
    usleep(400 * 1000);  // simulate work for 400ms
}

// Simple round-robin scheduler
void scheduler_round_robin(int total_cycles) {
    printf("\n=== Starting Round-Robin Scheduler ===\n\n");
    int current_task = 0;

    for (int cycle = 0; cycle < total_cycles; cycle++) {
        Task *t = &tasks[current_task];
        printf("[Cycle %d] Switching to %s\n", cycle+1, t->name);

        for (int tick = 0; tick < TICKS_PER_TASK; tick++) {
            printf("   [Tick %d] ", tick+1);
            run_task(t);
        }

        current_task = (current_task + 1) % NUM_TASKS;
    }
}

// Priority-based scheduler
void scheduler_priority(int total_cycles) {
    printf("\n=== Starting Priority-Based Scheduler ===\n\n");

    for (int cycle = 0; cycle < total_cycles; cycle++) {
        printf("[Cycle %d]\n", cycle+1);

        for (int p = 1; p <= NUM_TASKS; p++) {
            for (int i = 0; i < NUM_TASKS; i++) {
                if (tasks[i].priority == p) {
                    printf("   Running %s (priority %d)\n", tasks[i].name, p);
                    for (int tick = 0; tick < TICKS_PER_TASK; tick++) {
                        printf("      [Tick %d] ", tick+1);
                        run_task(&tasks[i]);
                    }
                }
            }
        }
    }
}

int main() {
    printf("=== RTOS Task Scheduler Simulation ===\n");

    init_tasks();

    int choice;
    printf("\nChoose Scheduler:\n");
    printf("1. Round-Robin\n");
    printf("2. Priority-Based\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    int cycles;
    printf("Enter number of cycles to run: ");
    scanf("%d", &cycles);

    if (choice == 1)
        scheduler_round_robin(cycles);
    else if (choice == 2)
        scheduler_priority(cycles);
    else
        printf("Invalid choice.\n");

    printf("\n=== Scheduler Finished ===\n");
    return 0;
}
