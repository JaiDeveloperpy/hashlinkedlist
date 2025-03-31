typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct {
    Node *head;
} List;

void insertNode(List *l){
    Node *aux, *newNode;
    aux = l->head;
    int newValue;
    printf("\n Qual valor será adicionado? ");
    scanf("%i", &newValue);
    newNode = malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->next = NULL;
    if (aux == NULL){
        l->head = newNode;
    }else{
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newNode;
    }
}
void insertAtBegin(List *l){
    Node *newNode;
    int newValue;
    printf("\n Informe o valor a ser adicionado a lista: ");
    scanf("%i", &newValue);
    newNode = malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->next = l->head;
    l->head = newNode;


}
void removeNode(List *l){
    Node *prev, *aux, *newNode;
    int removeValue, found = 0;
    prev = aux = l->head;
    printf("\n Informe o valor a ser removido. ");
    scanf("%i", &removeValue);
    if (aux == NULL){
        printf("\n A lista encontra-se vazia");
    }else{
        while (aux != NULL){
            if(removeValue == aux->value){
                found = 1;
                if (aux == l->head){
                    l->head = aux->next;
                    free(aux);
                    break;
                }else{
                    prev->next = aux->next;
                    free(aux);
                    break;
                }
            }else{
                prev = aux;
                aux= aux->next;
            }
        }
    }
    if (found = 0){
        printf("Elemento não encontrado na lista.");
    }
}
void findNode(List *l){
    Node *aux;
    int searchedValue, found = 0;

    aux = l->head;
    printf("\n Informe o valor a ser pesquisado: ");
    scanf("%i", &searchedValue);
    if (aux == NULL){
        printf("\n A lista está vazia");
    }else{
        while (aux != NULL){
            if (aux->value == searchedValue){
                found = 1;
                printf("\n O valor foi encontrado.");
                break;
            }else{
                aux = aux->next;
            }
        }
    }
    if (found == 0){
        printf("\n O valor nao foi encontrado na lista");
    }
}
void printList(List *l){
    Node *aux;
    aux = l->head;
    if (aux == NULL){
        printf("\n A lista encontra-se vazia");       
    }else{
        while (aux != NULL){
            printf("\n %d", aux->value);
            aux = aux->next;
        }
    }
    
}
int main (){
    Node *node1, *node2;
    List l;
    l.head = NULL;
    node1 = malloc(sizeof(Node));
    node2 = malloc(sizeof(Node));
    node1-> value = 10;
    node2->value=90;
    node1->next = node2;
    node2->next = NULL;
    l.head = node1;
    printList(&l);
    removeNode(&l);
    printList(&l);
    return 0;
}