class Funkcja
  def initialize(&block)
    if block.arity==1
      @func = block
    end
  end
  def value(x)
    return @func.call(x)
  end
  def zerowe(a,b,e)
    zera = []
    while a<=b
      if self.value(a)<=0.0001 and self.value(a)>=-0.0001
        zera += [a]
      end
      a+=e
    end
    if zera.size==0
      return nil
    end
    return zera
  end
  def poch(x)
    h=0.1
    return (self.value(x + h) - 2 * self.value(x) + self.value(x - h)) / (h * h)
  end
  def pole(a,b)
    h=0.000001
    n = (b - a) / h;
    integral = 0.0;
    1.upto(n.ceil) do |i|
      integral = integral + h * self.value(a + h * (i - 0.5))
    end
    return integral
  end
end

square = Funkcja.new {|x| x*x }
print square.value(5),"\n"
print square.zerowe(-5,5,1),"\n"
print square.poch(1),"\n" #musi byc okolo 2
print square.pole(0,3),"\n" #okolo 9
print "///////////////////////////////////////////////////\n"

############################################################
#ZAD2#######################################################
############################################################

class Funkcja2
  def initialize(&block)
    if block.arity==2
      @func = block
    end
  end
  def value(x,y)
    return @func.call(x,y)
  end
  def poziomica(a,b,c,d,wys)
    h=0.001
    step=1
    pary=[]
    a_l=a
    while c<=d
      while a_l<=b
        if self.value(a,c)-wys<=h and self.value(a,c)-wys>=-h
          pary += [[a_l,c]]
        end
        a_l+=step
      end
      c+=step
      a_l=a
    end
    return pary
  end
  def objetosc(a, b, c, d)
    return self.value((a+b)/2,(c+d)/2)*(b-a)*(d-c)
  end
end

mult = Funkcja2.new {|x,y| x*y }
print mult.value(1,2),"\n"
print mult.poziomica(-5,5,-10,10,0),"\n"
print mult.objetosc(1,5,1,2),"\n"
