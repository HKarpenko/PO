package javaapplication2;
import java.io.Serializable;

public class Element<T> implements Serializable{
        public Element(T data)
        {
            this.Data = data;
        }
        public T Data;
        public Element<T> Next;
}
