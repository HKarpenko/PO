package javaapplication4;
import java.io.Serializable;

public class Samochod extends Pojazd{
    Integer max_szybk;    
    public Samochod(int rok, String marka, int mph){
        super("Samochod",rok,marka);
        this.max_szybk=mph;
    }
    @Override
    public String toString(){
        return "Samochod marki: "+marka+"\nRok produkcji: "+rok_prod.toString()+
               "\nMax szybkoszcz: "+max_szybk.toString();
    }
}
