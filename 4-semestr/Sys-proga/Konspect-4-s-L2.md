# 22.03.2025
Системный вызов для работы с симаформаи в systemV:
1) semget - ```int semget(key_t key, int num_sem, int flag);``` key - имя, num_sem - кол-во семафоров в наборе, flag - ```IPC_CREAT, IPC_EXCL, perm```
2) semop - -1 - всё плохо, 0 - ок
```c
int semop(int semfd, struct sembuf* opPtr, int len); 
struct sembuf{
    sem_num // - номер
    sem_op // - операция. Может быть положительным, отрицательным и 0
    sem_ffg // - определение поведения!
}
``` 
3) semctl - 
```c
int semctl(int semId, int num, int cmd, union semun arg);
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
IPC_STAR
IPC_SET
IPC_RMID - удаление
GETALL - значение всех семафоров
SETALL - 
SETVAL
GETPID
GETNCNT
GETZCNT
```
Сист. вызовы для разделяемой памяти
1) shmget - ```int shmget(key-t key, int size, int flag);```
2) void *shmat(int shmId, void *addr, int flag);
3) int shmdt(void* oddr);
4) int shmctl(int shmid, int cmd, struct shmid_ds *buf);