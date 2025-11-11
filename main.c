// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>
// #include <string.h>

// int g_errors = 0;

// void test(char *name, int expected, int got)
// {
//     if (expected == got)
//         printf("✓ %s\n", name);
//     else
//     {
//         printf("✗ %s (expected %d, got %d)\n", name, expected, got);
//         g_errors++;
//     }
// }

// int main(void)
// {
//     int r1, r2;
    
//     printf("=== TESTS FT_PRINTF ===\n\n");
    
//     r1 = printf("A");    r2 = ft_printf("A");    test("char simple", r1, r2);
//     r1 = printf("%c", 'X'); r2 = ft_printf("%c", 'X'); test("%%c", r1, r2);
//     r1 = printf("%s", "hi"); r2 = ft_printf("%s", "hi"); test("%%s", r1, r2);
//     r1 = printf("%s", (char*)NULL); r2 = ft_printf("%s", (char*)NULL); test("%%s NULL", r1, r2);
//     r1 = printf("%p", &main); r2 = ft_printf("%p", &main); test("%%p", r1, r2);
//     r1 = printf("%d", -42); r2 = ft_printf("%d", -42); test("%%d négatif", r1, r2);
//     r1 = printf("%d", INT_MIN); r2 = ft_printf("%d", INT_MIN); test("%%d INT_MIN", r1, r2);
//     r1 = printf("%u", 0); r2 = ft_printf("%u", 0); test("%%u zero", r1, r2);
//     r1 = printf("%x", 255); r2 = ft_printf("%x", 255); test("%%x", r1, r2);
//     r1 = printf("%X", 255); r2 = ft_printf("%X", 255); test("%%X", r1, r2);
//     r1 = printf("%%"); r2 = ft_printf("%%"); test("%%%%", r1, r2);
    
//     printf("\n=== RÉSULTAT ===\n");
//     if (g_errors == 0)
//         printf("✓ Tous les tests passent !\n");
//     else
//         printf("✗ %d erreur(s) détectée(s)\n", g_errors);
    
//     return (g_errors);
// }


// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
//     int r1, r2;
    
//     printf("\n=== TESTS FT_PRINTF ===\n\n");
    
//     r1 = printf("%%c     : [%c]\n", 'A');           r2 = ft_printf("%%c     : [%c]\n", 'A');           printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%s     : [%s]\n", "Hello");       r2 = ft_printf("%%s     : [%s]\n", "Hello");       printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%s NULL: [%s]\n", (char*)NULL);   r2 = ft_printf("%%s NULL: [%s]\n", (char*)NULL);   printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%p     : [%p]\n", &main);         r2 = ft_printf("%%p     : [%p]\n", &main);         printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%p NULL: [%p]\n", NULL);          r2 = ft_printf("%%p NULL: [%p]\n", NULL);          printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%d     : [%d]\n", -42);           r2 = ft_printf("%%d     : [%d]\n", -42);           printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%d MIN : [%d]\n", INT_MIN);       r2 = ft_printf("%%d MIN : [%d]\n", INT_MIN);       printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%i     : [%i]\n", 42);            r2 = ft_printf("%%i     : [%i]\n", 42);            printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%u     : [%u]\n", 0);             r2 = ft_printf("%%u     : [%u]\n", 0);             printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%u MAX : [%u]\n", UINT_MAX);      r2 = ft_printf("%%u MAX : [%u]\n", UINT_MAX);      printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%x     : [%x]\n", 255);           r2 = ft_printf("%%x     : [%x]\n", 255);           printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%X     : [%X]\n", 255);           r2 = ft_printf("%%X     : [%X]\n", 255);           printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("%%%%    : [%%]\n");                r2 = ft_printf("%%%%    : [%%]\n");                printf("→ %d vs %d\n\n", r1, r2);
//     r1 = printf("MIX     : %s %d %x\n", "A", 1, 2); r2 = ft_printf("MIX     : %s %d %x\n", "A", 1, 2); printf("→ %d vs %d\n\n", r1, r2);
    
//     printf("=== FIN ===\n");
//     return (0);
// }

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int r1, r2;
    char *null_str = NULL;  // ✅ Variable pour éviter le warning
    
    printf("\n=== TESTS FT_PRINTF ===\n\n");
    
    r1 = printf("%%c     : [%c]\n", 'A');           
    r2 = ft_printf("%%c     : [%c]\n", 'A');           
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%s     : [%s]\n", "Hello");       
    r2 = ft_printf("%%s     : [%s]\n", "Hello");       
    printf("→ %d vs %d\n\n", r1, r2);
    
    // ✅ Utilisation de la variable au lieu de (char*)NULL
    r1 = printf("%%s NULL: [%s]\n", null_str);   
    r2 = ft_printf("%%s NULL: [%s]\n", null_str);   
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%p     : [%p]\n", &main);         
    r2 = ft_printf("%%p     : [%p]\n", &main);         
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%p NULL: [%p]\n", NULL);          
    r2 = ft_printf("%%p NULL: [%p]\n", NULL);          
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%d     : [%d]\n", -42);           
    r2 = ft_printf("%%d     : [%d]\n", -42);           
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%d MIN : [%d]\n", INT_MIN);       
    r2 = ft_printf("%%d MIN : [%d]\n", INT_MIN);       
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%i     : [%i]\n", 42);            
    r2 = ft_printf("%%i     : [%i]\n", 42);            
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%u     : [%u]\n", 0);             
    r2 = ft_printf("%%u     : [%u]\n", 0);             
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%u MAX : [%u]\n", UINT_MAX);      
    r2 = ft_printf("%%u MAX : [%u]\n", UINT_MAX);      
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%x     : [%x]\n", 255);           
    r2 = ft_printf("%%x     : [%x]\n", 255);           
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%X     : [%X]\n", 255);           
    r2 = ft_printf("%%X     : [%X]\n", 255);           
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("%%%%    : [%%]\n");                
    r2 = ft_printf("%%%%    : [%%]\n");                
    printf("→ %d vs %d\n\n", r1, r2);
    
    r1 = printf("MIX     : %s %d %x\n", "A", 1, 2); 
    r2 = ft_printf("MIX     : %s %d %x\n", "A", 1, 2); 
    printf("→ %d vs %d\n\n", r1, r2);
    
    printf("=== FIN ===\n");
    return (0);
}
