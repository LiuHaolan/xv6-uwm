#ifndef _USER_H_
#define _USER_H_

#include "pstat.h"
#include "thread.h"

struct stat;
struct lock_t;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

int getnumsyscallp(void);        // p1b
int getpinfo(struct pstat*);     // p2b
void *shmgetat(int key, int num_pages); // p3b
int shm_refcount(int key);       // p3b
int clone(void(*fcn)(void*), void*, void*);  // p4b
int join(void**);   // p4b


// user library functions (ulib.c)
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
void print_proc_info(struct pstat*, int);

// p4b thread libs
int thread_create(void(*start_routine)(void*), void*); 
int thread_join(void);
void lock_acquire(struct lock_t*);
void lock_release(struct lock_t*);
void lock_init(struct lock_t*);

#endif // _USER_H_

