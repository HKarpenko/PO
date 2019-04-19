package javaapplication1;

public class Wymnoz extends Wyrazenie{
    Wyrazenie Left;
    Wyrazenie Right;
    public Wymnoz(Wyrazenie l, Wyrazenie r){
        Left=l;
        Right=r;
    }
    public double oblicz(){
        return Left.oblicz() * Right.oblicz();
    }
    public String toString(){
            return "("+Left.toString()+"*"+Right.toString()+")";
    }
}