package javaapplication4;
import java.io.Serializable;


public class Tramwaj extends Pojazd{
    String organ;    
    public Tramwaj(int rok, String marka, String org){
        super("Tramwaj",rok,marka);
        this.organ=org;
    }
    @Override
    public String toString(){
        return "Tramwaj marki: "+marka+"\nRok produkcji: "+rok_prod.toString()+
               "\nOrganizacja: "+organ;
    }
}
