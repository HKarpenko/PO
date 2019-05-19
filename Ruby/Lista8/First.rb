class Integer
  def czynniki
    czyn=[]
    1.upto(self) do |x|
      if self%x==0
        czyn+=[x]
      end
    end
    czyn
  end
  def Ack(y)
    if self==0
      y+1
    elsif y==0
      (self-1).Ack(1)
    else
      (self-1).Ack(self.Ack(y-1))
    end
  end
  def doskonala
    czyn=self.czynniki-[self]
    sum = 0
    czyn.each { |a| sum+=a }
    if sum==self
      true
    else
      false
    end
  end
  def slownie
    to_str = {
      1 => "jeden",
      2 => "dwa",
      3 => "trzy",
      4 => "cztery",
      5 => "piec",
      6 => "szeszcz",
      7 => "siedem",
      8 => "osiem",
      9 => "dziewiec",
      0 => "zero"
    }
    str=""
    num=self
    while num!=0
      str=to_str[num%10]+" "+str
      num/=10
    end
    str
  end
end

print 6.czynniki,"\n"
print 2.Ack(1),"\n"
print 28.doskonala,"\n"
print 155.slownie
