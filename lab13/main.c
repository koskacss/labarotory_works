#include <stdio.h>

typedef struct
{
    unsigned char byte1:8;
    unsigned char byte2:8;
    unsigned char byte3:8;
    unsigned char byte4:8;
}ip;

ip ipv4_to_classC(ip ipv4); // Function for transform ipv4 in private address of class C

int main()
{
    short byte1, byte2, byte3, byte4;
    ip ipv4 , ipv4_class_c;

    puts("Input your Ipv4 address:\n(Example:x.x.x.x)\n");

    scanf("%hi.%hi.%hi.%hi", &byte1, &byte2, &byte3, &byte4);
    
    ipv4.byte1 = byte1;
    ipv4.byte2 = byte2;
    ipv4.byte3 = byte3;
    ipv4.byte4 = byte4;

    printf("\nYou have inputed: %d.%d.%d.%d\n", ipv4.byte1, ipv4.byte2, ipv4.byte3 , ipv4.byte4);

    ipv4_class_c = ipv4_to_classC(ipv4);

    printf("\nYour ip address of class C: %d.%d.%d.%d\n\n" , ipv4_class_c.byte1, ipv4_class_c.byte2, ipv4_class_c.byte3, ipv4_class_c.byte4);
    
    puts("Press any key to exit...");
    getchar();
    getchar();

    return 0;
}

ip ipv4_to_classC(ip ipv4)
{
    short x=192, x1 = 168;

    ipv4.byte1 = ipv4.byte1 & 0; // Обнуляем первый байт
    ipv4.byte2 = ipv4.byte2 & 0; // Обнуляем второй байт
    ipv4.byte1 = ipv4.byte1 | x; // Устанавливаем значение первого байта равным 192
    ipv4.byte2 = ipv4.byte2 | x1;// Устанавливаем значение второго байта равным 192

    return ipv4;
}