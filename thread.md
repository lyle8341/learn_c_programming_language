# 线程


+ example 1
  ```c
  #include <unistd.h> ////Header file for sleep(). man 3 sleep for details.
  #include <stdio.h>
  #include <pthread.h>
  
  void *myThreadFun(void *vargp) {
      sleep(3);
      printf("Printing GeeksQuiz from Thread\n");
      return NULL;
  }
  
  int main() {
      pthread_t thread_id;
      printf("Before Thread\n");
      /**
       * The first argument is a pointer to thread_id which is set by this function.
       * The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
       * The third argument is name of function to be executed for the thread to be created.
       * The fourth argument is used to pass arguments to the function, myThreadFun.
       */
      pthread_create(&thread_id, NULL, myThreadFun, NULL);
      //The pthread_join() function for threads is the equivalent of wait() for processes.
      // A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.
      pthread_join(thread_id, NULL);
      printf("After Thread\n");
      return 0;
  }
  ```
  
+ example 2
+ 

