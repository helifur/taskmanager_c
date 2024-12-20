#include <malloc.h>
#include <stdio.h>

#define AUTHOR "viamn"

void insert_task(char **tasks, int *size, char *task) {
  tasks[*size] = task;
  (*size)++;
}

void show_tasks(char **tasks, int size) {
  for (int i = 0; i < size; i++) {
    printf(" %s\n", tasks[i]);
  }
}

int main(void) {
  int size = 0;
  char **tasks = malloc(size * sizeof(char *));
  char action;
  FILE *tasks_data;

  printf("Hello! You're using task manager by %s.", AUTHOR);

  while (1) {
    printf("\n\nList of available actions:\n");
    printf("a) add task\nb) set task deadline\nc) set priority to task\nd)list "
           "all tasks\n");
    printf("What you want to do? Enter item, e. g. \"a, b, c, d\": ");

    scanf(" %c", &action);

    while (!('a' <= action && 'd' >= action)) {
      printf("Invalid choice! Enter item, e. g. \"a, b, c, d\": ");
      scanf(" %c", &action);
    }

    if (action == 'a') {
      printf("Enter new task: ");

      char *task = malloc(sizeof(char));
      scanf(" %s", task);

      insert_task(tasks, &size, task);
    }

    if (action == 'd') {
      show_tasks(tasks, size);
    }

    printf("Size: %d\n", size);
  }
  return 0;
}
