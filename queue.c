#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
    int value = serialize(state);
    insert_at_tail(&q->data,value);
}

struct game_state dequeue(struct queue *q) { 
    int value = remove_from_head(&q->data);
    return (deserialize(value)); 
}

int number_of_moves(struct game_state start) { 
    game_state *finish = (game_state*)malloc(sizeof(game_state));
    finish.tiles = {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15};
    finish.empty_col = 3;
    finish.empty_row = 3;
    /*
    node bfs(graph g, node start, node search) {
        queue q = new_queue();
        while (!empty(s)) {
            node cur = dequeue(&q);
            if (equals(cur, search)) {
                return cur;
            } else {
                for (node child in children(cur)) {
                    enqueue(&q, child);
                }
            }
        }
    }
    */
    queue *q = (queue*)malloc(sizeof(queue);)
    q->data.head = NULL;
    enqueue(&q,start);
    while ((q->data.head) != NULL){
        dequeue(&q);
        list_node cur = q->data.head;
        if ((finish.tiles == start.tiles) & (finish.empty_col == start.empty_col)){
            return start.num_steps;
        } else {
            bool found = false;
            list_node *p = q->data.head;
            while (q->data.head.next != NULL){
                q->data.head = q->data.head.next;
                if (serialize(start) == q->data.head.value){
                    found = true;
                }
            }
            q->data.head = p;
            if (found == false){
                for (int i = start.empty_row; i<3 ; i++){
                    for (int j = start.empty_col; j<3 ;j++){
                        move_left(&start);
                        enqueue(&q,start);
                    }
                    move_down(&start);
                }
            }
        }
    }

    free_list(q->data);
    free(q);
    return start.num_steps; 
}

bool solved(struct *queue cur){
    int a = 1;
    for (int i = 0; i < 4; i++){

    }
}