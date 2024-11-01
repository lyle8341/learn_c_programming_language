# Atomic

+ **int a;时的 a++**
  ```asm
  mov     eax, DWORD PTR a[rip]
  add     eax, 1
  mov     DWORD PTR a[rip], eax
  ```
+ **_Atomic int a; 时的 a++**
  ```asm
  mov     DWORD PTR [rbp-12], 1
  mov     eax, DWORD PTR [rbp-12]
  lock xadd       DWORD PTR a[rip], eax
  mov     DWORD PTR [rbp-8], eax
  ```
  + `xadd       DWORD PTR a[rip], eax`把三条CPU指令变成一条原子的指令
  + lock把总线锁住，避免多CPU之间的总线竞争