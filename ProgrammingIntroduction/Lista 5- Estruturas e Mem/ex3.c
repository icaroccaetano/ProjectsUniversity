#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * paises[24] = {"brail", "alemaha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
			"inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
			"mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
			"marrocos", "japao" };

char * traducao[24] = {"Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
				"Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
				"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
				"Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
				"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"};

typedef struct
{
    pais[50];
    traduçao[50];
} tradutor;

int findlan (char c[50]); 

int main (void)
{
    char c[50];
    int i, t;

    while (c[i]!= "/*")
    {
        scanf("%c", &c[i]);
        i++;
    }

    t = findlan (c);

    printf("%s", traducao[t]);
}

int findlan (char c[50])
{
    int i;
    for (i=0;i<24;i++)
    {
        if (c = paises[i])
            return i;
    }
}

strcp

