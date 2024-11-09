# Двоичное дерево (Бинарные деревья)
## Что такое бинарное дерево?
![Деревья.jpg](pictures/Деревья.jpg)\
Объявление структуры
```c
struct TreeNode{
    int data;
    struct TreeNode *pleft;
    struct TreeNode *pright;
};
```
Необходимо иметь правило для сравнения данных, которые могут содержаться в *data*.\
Это позволяет реализовывать **быстрый поиск данных**.\
Сложность обхода сбалансированного дерева **O(log(n))**;\
![Пример_дерева.jpg](pictures/Пример_деревьев.jpg)\
Правое дерево считается вырожденным, поэтому сложность в этом случае **O(n)**
Такое дерево теряет все свои преимущества в поиске.
## Обход двоичного дерева
```c
void PrintTree(struct TreeNode *root){
    if (root == NULL){
        return;
    }
    PrintTree(root->pleft);
    printf("%d\n", root->data);
    PrintTree(root->pright);
}
```
Если строить дерево из отсортированного файла, то получится вырожденное дерево.\
## Поиск со вставкой
Элемент поиска необходимо найти в дереве:
+ Если он найден, то уведомить об этом 
+ Если он не найден, то добавить его в дерево.

Реализация с помощью рекурсии
```c
struct TreeNode *insert(struct TreeNode *root, int element){
    if (root == NULL) {
        root = CreateNode(element);
        return root;
    }
    if (root->data == element){
        return root;
    }
    else if (root->data > element){
        if (root->pleft == NULL){
            root->pleft = CreateNode(element);
            return root->pleft;
        }
        insert(root->pleft, element);
    }
    else {
        if (root->pright == NULL){
            root->pright = CreateNode(element);
            return root->pright;
        }
        insert(root->pleft, element);
    }
}
```

Реализация без рекурсии:
```c
struct TreeNode *insert(struct TreeNode * root, int element){
    struct TreNode = root;
    while (ptr != NULL){
    if(prt->data == element){
        return prt;
    }
    else if (ptr->data > element){
        if(ptr->pleft == NULL){
            ptr->pleft = CreatrNode(element);
            return ptr->pleft;
        }
        ptr = ptr->pleft;
    }
    else{
         if(ptr->pright == NULL){
            ptr->pright = CreatrNode(element);
            return ptr->pright;
        }
        ptr = ptr->pright;
    }
}
}
```
