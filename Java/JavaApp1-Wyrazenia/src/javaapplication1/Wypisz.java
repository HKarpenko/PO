package javaapplication1;

public class Wypisz extends Wyrazenie{
        Wyrazenie print_wyr;
        public Wypisz(Wyrazenie wyr){
            print_wyr=wyr;
        }
        public double oblicz(){
            System.out.println(print_wyr.oblicz());
            return print_wyr.oblicz();
        }
        public String toString(){
            return "print("+print_wyr.toString()+")";
        }
    } 
