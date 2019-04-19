package javaapplication2;
import java.io.Serializable;

public class Lista<T> implements Serializable{
     Element<T> start=null;
     Element<T> end=null;
     int len=0;
    public boolean Empty(){ 
        return len == 0; 
    }
    public void Add_to_end(T data) {
        Element<T> new_el = new Element(data);
        if (start == null)
            start = new_el;
        else
            end.Next = new_el;
        end = new_el;
        len++;
    }
    public void Add_to_start(T data) {
        Element<T> new_el = new Element(data);
        new_el.Next = start;
        start = new_el;
        if (len == 0)
            end = start;
        len++;
    }
    public T Delete_from_start() {
        if (start == null)
            return null;
        len--;
        T ret = start.Data;
        start = start.Next;
        return ret;
    }
    public T Delete_from_end(){
        if (start == null)
            return null;
        len--;
        T ret = end.Data;
        if (start.Next == null){
            start = null;
            end = null;
            return ret;
        }
        Element<T> current = start;
        while (current.Next != end)
            current = current.Next;
        current.Next = null;
        end = current;
        return ret;
    }
};