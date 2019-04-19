package javaapplication1;
import java.util.*; 

public class JavaApplication1 {
    
    public static void main(String[] args) {
        Zmienna.wloz("y", 20);
        Wyrazenie wyrazenie1 = new Dodaj(new Stala(4), new Zmienna("x",10));
        Wyrazenie wyrazenie2 = new Wymnoz(new Zmienna("y"), new Stala(5));
        Wyrazenie wyrazenie3 = new Odejmij(wyrazenie2, wyrazenie1);
        Wyrazenie wyrazenie4 = new Podziel(wyrazenie3, wyrazenie1);
        System.out.println(wyrazenie1.toString());
        System.out.println(wyrazenie2.toString());
        System.out.println(wyrazenie3.toString());
        System.out.println(wyrazenie4.toString());
        System.out.println(wyrazenie1.oblicz());
        System.out.println(wyrazenie2.oblicz());
        System.out.println(wyrazenie3.oblicz());
        System.out.println(wyrazenie4.oblicz());
        System.out.println("::::::::::::::::::::::::::::::::::::::");
        Zmienna.wloz("i", 1);
        Zmienna.wloz("sil", 1);
        Wyrazenie wyrazenie5 = new Przypisz(new Zmienna("i"),new Dodaj(new Zmienna("i"),new Stala(1)));
        Wyrazenie wyrazenie6 = new Przypisz(new Zmienna("sil"),new Wymnoz(new Zmienna("sil"),new Zmienna("i")));        
        Wyrazenie[] silnia = new Wyrazenie[2];
        silnia[0]=wyrazenie6;
        silnia[1]=wyrazenie5;
        Wyrazenie wyrazenie7 = new Powtorz(new Stala(6),silnia);
        wyrazenie7.oblicz();
        System.out.println(wyrazenie7.toString());
        Wyrazenie wyrazenie8 = new Wypisz(new Zmienna("sil"));
        System.out.println(wyrazenie8.toString());
        wyrazenie8.oblicz();
    }
    
}
