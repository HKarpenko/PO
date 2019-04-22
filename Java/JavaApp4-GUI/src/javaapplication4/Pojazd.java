package javaapplication4;
import java.io.*;
import java.io.Serializable;

public class Pojazd {
    String typ;
    Integer rok_prod;
    String marka;
    public Pojazd(String typ, int rok, String marka){
        this.typ=typ;
        this.rok_prod=rok;
        this.marka=marka;
    }
    @Override
    public String toString(){
        return "Pojazd typu: "+typ+"\nRok produkcji: "+rok_prod.toString()+
               "\nMarka: "+marka;
    }
    public void Zapisz(String file){
        try{
            ObjectOutputStream Out = new ObjectOutputStream(new FileOutputStream(file));
            Out.writeObject(this);
            Out.close();
        }
        catch(IOException e){}
    }
    public static Pojazd Wczytaj(String file) throws IOException {
        try{
            ObjectInputStream In = new ObjectInputStream(new FileInputStream(file));
            return (Pojazd)In.readObject();
        }
        catch(ClassNotFoundException e ){}
        return null;
    }
}
