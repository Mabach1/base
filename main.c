#include "base/base.h"

typedef struct _Person {
    usize id;
    String name;
    String surname;
} Person;

typedef struct _Node {
    Person person;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node *list_find_node(Node *head, usize person_id) {
    for (Node *n = head; n; n = n->next) {
        if (n->person.id == person_id) {
            return n;
        }
    }
    return NULL;
}

void list_add(Pool *pool, Node **head, Person data) {
    if (list_find_node(*head, data.id)) {
        std_print_stream(stdout, "Error when adding a new person to the list. Person with this id: %llu, already exists\n", data.id);
        return;
    }

    Node *new_node = pool_alloc(pool);

    ASSERT(new_node, "Error: Not enough memory");

    new_node->person = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (NULL == *head) {
        *head = new_node;
        return;
    }

    Node *last = *head; 

    while (last->next) { last = last->next; }

    last->next = new_node;
    new_node->prev = last;
}

void node_print(Node *n) {
    if (!n) {
        LOG("Empty node");
        return;
    }

    std_print_stream(stdout, "{u}: {s} {s}\n", n->person.id, n->person.name, n->person.surname);
}
 
void list_print(Node *head) {
    if (!head) {
        std_print_stream(stdout, "Trying to print an empty list\n");
        return;
    }
    
    for (Node *n = head; n; n = n->next) {
        node_print(n);
    }
}

Person get_new_person(Arena *arena) {
    Person result;

    std_print_stream(stdout, "Id: ");
    scanf(" %llu", &result.id);

    std_print_stream(stdout, "Name: ");
    result.name = string_from_stdin(arena);

    std_print_stream(stdout, "Surname: ");
    result.surname = string_from_stdin(arena);

    return result;
}

i32 main(void) {
    Arena arena;
    arena_init(&arena);

    Pool pool;
    pool_init(&pool, sizeof(Node));

    Node *head = NULL;

    StringArr options = stringarr_alloc(&arena, 4);

    stringarr_push_multiple(&options, 4, 
        string_from(&arena, "exit"),
        string_from(&arena, "add new person"),
        string_from(&arena, "print list"),
        string_from(&arena, "find person (using their id)")
    );

    while (true) {
        switch (menu(options)) {
            case 0: 
                std_print_stream(stdout, "Exiting...\n");
                exit(EXIT_SUCCESS); 
                break;
            case 1:
                list_add(&pool, &head, get_new_person(&arena));
                break;
            case 2:
                list_print(head);
                break;
            case 3:
                TODO("getting an id from the user");
                break;
            default:
                ;
        }
        menu_pause();
    }

    pool_deinit(&pool);
    arena_deinit(&arena);

    return 0;
}
