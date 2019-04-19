package javaapplication1;

public class Stala extends Wyrazenie{
    Double wart;
    public Stala(double w){
        this.wart=w;
    }
    public double oblicz(){
        return wart;
    }
    public String toString(){
            return wart.toString();
    }
}
