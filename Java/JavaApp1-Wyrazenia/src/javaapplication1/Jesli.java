package javaapplication1;

public class Jesli extends Wyrazenie{
        Wyrazenie warunek;
        Wyrazenie if_war;
        Wyrazenie else_war;
        public Jesli(Wyrazenie war, Wyrazenie p, Wyrazenie f){
            warunek=war;
            if_war=p;
            else_war=f;
        }
        public double oblicz(){
            if(warunek.oblicz()!=0)
                return if_war.oblicz();
            return else_war.oblicz();
        }
        public String toString(){
            return "if("+warunek+") then: "+if_war.toString()+" else: "+else_war.toString();
        }
    } 
