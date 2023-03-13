#0x0B. C - malloc, free


task 0. Float like a butterfly, sting like a bee

Write a function that creates an array of chars, and initializes it with a specific char.

Prototype: char *create_array(unsigned int size, char c);
Returns NULL if size = 0
Returns a pointer to the array, or NULL if it fails

Repo:

GitHub repository: alx-low_level_programming
Directory: 0x0B-malloc_free
File: 0-create_array.c


task 1: The woman who has no imagination has no wings

Write a function that returns a pointer to a newly allocated space in memory, 
which contains a copy of the string given as a parameter.

Prototype: char *_strdup(char *str);
The _strdup() function returns a pointer to a new string which is a duplicate of the string str. 
Memory for the new string is obtained with malloc, and can be freed with free.
Returns NULL if str = NULL
On success, the _strdup function returns a pointer to the duplicated string. 
It returns NULL if insufficient memory was available

Repo:

GitHub repository: alx-low_level_programming
Directory: 0x0B-malloc_free
File: 1-strdup.c

