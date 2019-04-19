package javaapplication1;

public class Podziel extends Wyrazenie{
    Wyrazenie Left;
    Wyrazenie Right;
    public Podziel(Wyrazenie l, Wyrazenie r){
        Left=l;
        Right=r;
    }
    public double oblicz(){
        return Left.oblicz() / Right.oblicz();
    }
    public String toString(){
            return "("+Left.toString()+"/"+Right.toString()+")";
    }
}
