#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_to_num(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return 0;
}

long long base_to_decimal(const char* value, int base) {
    long long result = 0;
    int len = strlen(value);
    
    for (int i = 0; i < len; i++) {
        int digit = char_to_num(value[i]);
        if (digit >= base) {
            return 0; 
        }
        result = result * base + digit;
    }
    
    return result;
}

typedef struct {
    long long x, y;
} Point;


long long find_secret(Point* points, int k) {
    long double result = 0.0L;
    
    for (int i = 0; i < k; i++) {
        long double term = points[i].y;
        
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term = term * (0.0L - points[j].x) / (points[i].x - points[j].x);
            }
        }
        
        result += term;
    }
    
    return (long long)(result > 0 ? result + 0.5L : result - 0.5L);
}

int main() {
    printf("Test Case 1:\n");
    Point test1[] = {
        {1, base_to_decimal("4", 10)},
        {2, base_to_decimal("111", 2)},
        {3, base_to_decimal("12", 10)},
        {6, base_to_decimal("213", 4)}
    };

    for (int i = 0; i < 4; i++) {
        printf("Point %d: (%lld, %lld)\n", i+1, test1[i].x, test1[i].y);
    }
    
    long long secret1 = find_secret(test1, 3); 
    printf("Secret: %lld\n\n", secret1);

    printf("Test Case 2:\n");
    Point test2[] = {
        {1, base_to_decimal("13444211440455345511", 6)},
        {2, base_to_decimal("aed7015a346d635", 15)},
        {3, base_to_decimal("6aeeb69631c227c", 15)},
        {4, base_to_decimal("e1b5e05623d881f", 16)},
        {5, base_to_decimal("316034514573652620673", 8)},
        {6, base_to_decimal("2122212201122002221120200210011020220200", 3)},
        {7, base_to_decimal("20120221122211000100210021102001201112121", 3)}
    };

    for (int i = 0; i < 7; i++) {
        printf("Point %d: (%lld, %lld)\n", i+1, test2[i].x, test2[i].y);
    }
    
    long long secret2 = find_secret(test2, 7); // Use all 7 points (k=7)
    printf("Secret: %lld\n", secret2);
    
    return 0;
}
