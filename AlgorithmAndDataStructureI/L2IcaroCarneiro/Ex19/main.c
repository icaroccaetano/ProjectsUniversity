#include "tad.h"

int main (void)
{
    Pilha pilha;
    // Testes da funcao palindromo
    // Teste 1 - "reviver"
    init (&pilha);
    empilha (&pilha,'r');
    empilha (&pilha,'e');
    empilha (&pilha,'v');
    empilha (&pilha,'i');
    empilha (&pilha,'v');
    empilha (&pilha,'e');
    empilha (&pilha,'r');
    palindromo (&pilha);
    limpapilha (&pilha);    
    // Teste 2 - "meu nome e icaro"
    init (&pilha);
    empilha (&pilha,'m');
    empilha (&pilha,'e');
    empilha (&pilha,'u');
    empilha (&pilha,' ');
    empilha (&pilha,'n');
    empilha (&pilha,'o');
    empilha (&pilha,'m');
    empilha (&pilha,'e');
    empilha (&pilha,' ');
    empilha (&pilha,'e');
    empilha (&pilha,' ');
    empilha (&pilha,'i');
    empilha (&pilha,'c');
    empilha (&pilha,'a');
    empilha (&pilha,'r');
    empilha (&pilha,'o');
    palindromo (&pilha);
    limpapilha (&pilha);    
    // Teste 3 - "ame o poema"
    init (&pilha);
    empilha (&pilha,'a');
    empilha (&pilha,'m');
    empilha (&pilha,'e');
    empilha (&pilha,' ');
    empilha (&pilha,'o');
    empilha (&pilha,' ');
    empilha (&pilha,'p');
    empilha (&pilha,'o');
    empilha (&pilha,'e');
    empilha (&pilha,'m');
    empilha (&pilha,'a');
    palindromo (&pilha);
    limpapilha (&pilha);
    // Teste 4 - "socorram me subi no onibus em marrocos"
    init (&pilha);
    empilha (&pilha,'s');
    empilha (&pilha,'o');
    empilha (&pilha,'c');
    empilha (&pilha,'o');
    empilha (&pilha,'r');
    empilha (&pilha,'r');
    empilha (&pilha,'a');
    empilha (&pilha,'m');
    empilha (&pilha,' ');
    empilha (&pilha,'m');
    empilha (&pilha,'e');
    empilha (&pilha,' ');
    empilha (&pilha,'s');
    empilha (&pilha,'u');
    empilha (&pilha,'b');
    empilha (&pilha,'i');
    empilha (&pilha,' ');    
    empilha (&pilha,'n');
    empilha (&pilha,'o');
    empilha (&pilha,' ');
    empilha (&pilha,'o');
    empilha (&pilha,'n');
    empilha (&pilha,'i');
    empilha (&pilha,'b');
    empilha (&pilha,'u');
    empilha (&pilha,'s');
    empilha (&pilha,' ');
    empilha (&pilha,'e');
    empilha (&pilha,'m');
    empilha (&pilha,' ');
    empilha (&pilha,'m');
    empilha (&pilha,'a');
    empilha (&pilha,'r');
    empilha (&pilha,'r');
    empilha (&pilha,'o');
    empilha (&pilha,'c');
    empilha (&pilha,'o');
    empilha (&pilha,'s');
    palindromo (&pilha);

    return SUCCESS;
}