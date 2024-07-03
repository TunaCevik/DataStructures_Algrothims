#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    //matrix' in Row sayısı;
    int Matrix_R;
    //matrix' in Column sayısı;
    int Matrix_C;
    //2D matrix in elemenlarını içerir
    double *matrixunits;
    // LinkedList için sıradaki node' u tutar
    struct Node* next;
} Node;

typedef struct  {
    //Stackin içinde kaç Node oluğunu söyler
    int MatrixSC;
    //double* matrixS' te olabilecek Max kapasiteyi belirtir (Node olarak)
    int Stack_Capacity;
    //Nodeları dizi gibi sırayla tutar
    Node *matrixS;
} Stack;

typedef struct {
    //linkedListe kaç elemena oluduğunu söyler
    int MatrixLC;
    //Head Node' u tutar
    Node *head;
    //Tail Node' u tutar
    Node *tail;
} LinkedListQ;


Node *CreateNode();
Stack *CreateStack(int StackCapacity);
LinkedListQ *CreateLinkedListQ();

//Public Function
void Menu();
void print2DArrayAs1D(double *array, int rows, int cols);
void freeNode(Node* node);
/*---------------------------------------------------*/

//Stack Function
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool push(Stack *stack, Node *node);
bool pop(Stack *stack, Node *node);
bool peek(Stack *stack, Node *node);
void destroy_stack(Stack *stack);
void printfMatrix_Stack(Stack *stack);
void MenuStack();

/*---------------------------------------------------*/

//LinkedList Function Q
int size_Link(LinkedListQ *queue);
bool is_empty_Link(LinkedListQ *queue);
double  *peek_Link(LinkedListQ *queue, bool *status);
void enqueue_Link(LinkedListQ *queue, Node *node);
double *dequeue_Link(LinkedListQ *queue, bool *status);
void destroy_queue_Link(LinkedListQ *queue);
void printfMatrix_LinkedList(LinkedListQ *linkedlistq);
void MenuLinkedListQ();

/*---------------------------------------------------*/

int main() {
    LinkedListQ *LLQ = CreateLinkedListQ();
    Stack *STACK = CreateStack(5);
    int choicesMain, choices;
    Node *NODEX = NULL;
    bool status = false;

    do {
        Menu();
        printf("\nPlease enter which action you want to take: ");
        scanf("%d", &choicesMain);
        switch (choicesMain) {
        case 0:
            // Programı ve tüm kaynakları temizle ve çık
            destroy_queue_Link(LLQ);
            destroy_stack(STACK);
            return 0;  // Döngüyü kır ve programdan çık

        case 1:  // Gösterim Matrisi
            puts("1. Print Matrix from Stack");
            puts("2. Print Matrix from Linked List");
            printf("Please choose an option: \n");
            scanf("%d", &choices);
            if (choices == 1) {
                printfMatrix_Stack(STACK);
            } else if (choices == 2) {
                printfMatrix_LinkedList(LLQ);
            }
            break;

        case 2:  // Yığın (Stack) işlemleri
            MenuStack();
            do {
                printf("\nPlease enter which action you want to take: ");
                scanf("%d", &choices);
                if (choices == 0) break;  // Yığın menüsünden çık

                switch (choices) {
                case 1:  // Push
                    NODEX = CreateNode();
                    if (NODEX && push(STACK, NODEX)) {
                        puts("Pushed successfully.");
                    } else {
                        puts("Failed to push.");
                        freeNode(NODEX);
                    }
                    break;
                case 2:  // Pop işlemi
                    if (pop(STACK, NODEX)) {  // NODEX adresi ile pop fonksiyonunu çağır
                        puts("Popped successfully.");
                        if (NODEX != NULL) {
                            print2DArrayAs1D(NODEX->matrixunits, NODEX->Matrix_R, NODEX->Matrix_C);
                            // Burada NODEX ile ilgili diğer işlemleri yapabilirsiniz.
                        }
                    } else {
                        puts("Stack is empty, cannot pop.");
                    }
                    break;

                case 3:  // Peek
                    Node *peekNode = NULL;  // Yeni bir Node pointer tanımla, başlangıçta NULL
                    if (peek(STACK, peekNode)) {  // peekNode, STACK'ten en üstteki Node'un adresini alacak
                        print2DArrayAs1D(peekNode->matrixunits, peekNode->Matrix_R, peekNode->Matrix_C);
                    } else {
                        puts("Stack is empty, nothing to peek.");
                    }
                    break;
                }
            } while (choices != 0);
            break;

        case 3:  // Bağlı Liste İşlemleri
            MenuLinkedListQ();
            do {
                printf("\nPlease enter which action you want to take: ");
                scanf("%d", &choices);
                if (choices == 0) break;  // Bağlı liste menüsünden çık

                switch (choices) {
                case 1:  // Enqueue
                    NODEX = CreateNode();
                    if (NODEX) {
                        enqueue_Link(LLQ, NODEX);
                        puts("Enqueue done.");
                    }
                    break;
                case 2:  // Dequeue
                    double *dequeueMatrix = dequeue_Link(LLQ, &status);
                    if (status) {
                        puts("Dequeue done.");
                        print2DArrayAs1D(dequeueMatrix, NODEX->Matrix_R, NODEX->Matrix_C);
                    }
                    break;
                case 3:  // Peek
                    double *peekMatrix = peek_Link(LLQ, &status);
                    if (status) {
                        print2DArrayAs1D(peekMatrix, NODEX->Matrix_R, NODEX->Matrix_C);
                    }
                    break;
                }
            } while (choices != 0);
            break;

        case 4:  // Matris Hesaplamaları
            break;
        }

    } while (choicesMain != 0);

    return 0;
}


Node *CreateNode() {
    int MatrixR, MatrixC;
    puts("Please enter the number of rows for your matrix:");
    scanf("%d", &MatrixR);
    puts("Please enter the number of columns for your matrix:");
    scanf("%d", &MatrixC);

    Node *Matrix_Node = malloc(sizeof(Node));
    if (Matrix_Node == NULL) {
        puts("Memory allocation for Node failed.");
        return NULL;
    }

    Matrix_Node->matrixunits = malloc(sizeof(double) * MatrixC * MatrixR);
    if (Matrix_Node->matrixunits == NULL) {
        puts("Memory allocation for matrix units failed.");
        free(Matrix_Node);
        return NULL;
    }

    Matrix_Node->Matrix_C = MatrixC;
    Matrix_Node->Matrix_R = MatrixR;
    Matrix_Node->next = NULL;

    printf("Enter the elements for the %dx%d matrix, row by row:\n", MatrixR, MatrixC);
    for (int i = 0; i < MatrixR; i++) {
        for (int j = 0; j < MatrixC; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &Matrix_Node->matrixunits[i * MatrixC + j]);
        }
    }

    return Matrix_Node;
}
Stack *CreateStack(int StackCapacity) {
    if(StackCapacity == 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->matrixS = malloc(sizeof(Node) * StackCapacity);
    if(stack->matrixS == NULL) {
        free(stack);
        return NULL;
    }
    stack->Stack_Capacity = StackCapacity;
    stack->MatrixSC = 0;

    return stack;
}
LinkedListQ *CreateLinkedListQ() {
    LinkedListQ *linkedlist = malloc(sizeof(LinkedListQ));
    if(linkedlist == NULL) return NULL;

    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->MatrixLC = 0;

    return linkedlist;
}

//StackFunctions

bool is_full(Stack *stack) {
    return stack->Stack_Capacity == stack->MatrixSC;
}
bool is_empty(Stack *stack) {
    return stack->MatrixSC == 0;
}
bool push(Stack *stack, Node *node) {
    bool is_full(Stack *stack);
    if(is_full(stack)) return false;
    
    stack->matrixS[stack->MatrixSC] = *node;
    stack->MatrixSC++;

    return true;
}
bool pop(Stack *stack, Node *node) {
    if (is_empty(stack)) return false;  // Yığın boşsa false döndür

    stack->MatrixSC--;  // Stack sayacını azalt
    *node = stack->matrixS[stack->MatrixSC];  // Node pointer'ını güncelle

    return true;  // Başarıyla pop yapıldı
}
bool peek(Stack *stack, Node *node) {
    bool is_empty(Stack *stack);
    if (is_empty(stack)) return false;
  
    *node = stack->matrixS[stack->MatrixSC - 1];

    return true;
}
void destroy_stack(Stack *stack)
{
  free(stack->matrixS);
  free(stack);
}
void printfMatrix_Stack(Stack *stack) {
    if (stack == NULL || stack->MatrixSC == 0) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contains %d matrices:\n", stack->MatrixSC);
    for (int i = 0; i < stack->MatrixSC; i++) {
        Node current = stack->matrixS[i];
        printf("Matrix %d (%d x %d):\n", i + 1, current.Matrix_R, current.Matrix_C);
        for (int row = 0; row < current.Matrix_R; row++) {
            for (int col = 0; col < current.Matrix_C; col++) {
                printf("%8.2f ", current.matrixunits[row * current.Matrix_C + col]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void MenuStack() {
    puts("0. Exit");
    puts("1. Push");   
    puts("2. Pop");
    puts("3. Peek");
}
//LinkedListQ

int size_Link(LinkedListQ *queue) {
    return queue->MatrixLC;
}
bool is_empty_Link(LinkedListQ *queue) {
    return queue->MatrixLC == 0;
}
double  *peek_Link(LinkedListQ *queue, bool *status) {
    bool is_empty_Link(LinkedListQ *queue);
    if((is_empty_Link(queue))) {
        *status = false;
        return NULL;
    }
    *status = true;

    return queue->head->matrixunits;
}
void enqueue_Link(LinkedListQ *queue, Node *node) {
    bool is_empty_Link(LinkedListQ *queue);

    Node *newNode = malloc(sizeof(Node));
    
    newNode = node;

    newNode->next = NULL;

    if(is_empty_Link(queue)) {
        queue->head = newNode; 
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->MatrixLC++;
}
double *dequeue_Link(LinkedListQ *queue, bool *status) {
    bool is_empty_Link(LinkedListQ *queue);
    if(is_empty_Link(queue)) {
        *status = false;
        return NULL;
    }

    *status = true;

    double *value = queue->head->matrixunits;

    Node *oldhead = queue->head;

    if(queue->MatrixLC == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
    }

    free(oldhead);

    queue->MatrixLC--;

    return value;
}
void destroy_queue_Link(LinkedListQ *queue) {
    Node *currentNode = queue->head;
    Node *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode->matrixunits);
        free(currentNode);
        currentNode = nextNode;
    }

    free(queue);
}
void printfMatrix_LinkedList(LinkedListQ *linkedlistq) {
    if (linkedlistq == NULL || linkedlistq->head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    int count = 1;
    Node *currentNode = linkedlistq->head;
    printf("LinkedList contains %d matrices:\n", linkedlistq->MatrixLC);
    while (currentNode != NULL) {
        printf("Matrix %d (%d x %d):\n", count, currentNode->Matrix_R, currentNode->Matrix_C);
        for (int row = 0; row < currentNode->Matrix_R; row++) {
            for (int col = 0; col < currentNode->Matrix_C; col++) {
                printf("%8.2f ", currentNode->matrixunits[row * currentNode->Matrix_C + col]);
            }
            printf("\n");
        }
        printf("\n");
        currentNode = currentNode->next;
        count++;
    }
}
void MenuLinkedListQ() {
    puts("0. Exit");
    puts("1. Enqueue");   
    puts("2. Dequeue");
    puts("3. Peek");
}
//Public Functions

void Menu() {
    puts("0. Exit and free all stack & linkedlist");
    puts("1. Showing Matrixs");   
    puts("2. (Stack) Push & Pop & Peek");
    puts("3. (Linked List) Enqueue & Dequeue & Peek");
    puts("4. Matrix Calculations");
}
void freeNode(Node* node) {
    if (node == NULL) return;

    // İlk olarak matris elemanlarını tutan dizi serbest bırakılır
    free(node->matrixunits);

    // Node yapı türünün kendisini serbest bırak
    free(node);
}
void print2DArrayAs1D(double *array, int rows, int cols) {
    if (array == NULL) {
        printf("Array pointer is NULL.\n");
        return;
    }

    printf("Printing 2D array stored in 1D format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", array[i * cols + j]);
        }
        printf("\n");
    }
}
