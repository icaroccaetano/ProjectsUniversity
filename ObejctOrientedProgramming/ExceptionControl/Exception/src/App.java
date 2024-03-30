/* 
Icaro Carneiro Caetano Cherednikov
202103732
Professor Dirson Campos 
*/



import java.util.InputMismatchException;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        int a=0, b=0;
        int contador = 0;
        try {
            do {                
                try {
                    if (contador == 0) {
                        a = input (0);
                        contador = 1;
                    }
                    if (contador == 1) {
                        b = input (1);
                        contador = 2;
                    }
                }
                catch (ArithmeticException e) {
                    System.out.println(e.getMessage());
                }
                catch (InputMismatchException e) {
                    System.out.println(e.getMessage());
                }
            } while (contador<2);
        }
        finally {
            System.out.println("Resultado: " + a/b);
            System.out.println("Programa encerrado.");
        }
    }

    public static int input (int x) throws InputMismatchException, ArithmeticException {
        int n = 1;
        Scanner ler = new Scanner(System.in);
        switch (x) {
            case 0: //numerador
                System.out.println("Digite o numerador:");
                try {
                    n = ler.nextInt();
                } catch (InputMismatchException e) {
                    throw new InputMismatchException("Erro: inserir apenas numeros inteiros.");
                }   
                break;
            case 1: //denominador
                System.out.println("Digite o denominador:");
                try {
                    n = ler.nextInt();
                    if (n==0) throw new ArithmeticException("Erro: denominador nao pode ser zero.");
                } 
                
                catch (InputMismatchException e) {
                    throw new InputMismatchException("Erro: inserir apenas numeros inteiros.");
                }   
                break;
            default:
                break;
        }
        return n;
    }
}  
