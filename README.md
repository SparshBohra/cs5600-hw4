CS5600 HW4

ch13 - memory-user.c (free / pmap experiments)
ch14 - malloc bug demos + small realloc vector

build/run examples (on Linux VM):

ch13:
  gcc -O2 -o memory-user memory-user.c
  ./memory-user 100 30

ch14:
  gcc -g -o null null.c
  gcc -g -o leak leak.c
  gcc -g -o overrun overrun.c
  gcc -g -o use_after_free use_after_free.c
  gcc -g -o bad_free bad_free.c
  gcc -g -o vector vector.c
  valgrind --leak-check=yes ./leak
