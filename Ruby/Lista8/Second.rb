class Jawna
  def initialize(str)
    @napis = str
  end
  def get_str
    @napis
  end
  def zaszyfruj(klucz)
    szyfr=""
    @napis.each_char do |sym|
      szyfr+=klucz[sym]
    end
    @zasz_ob = Zaszyfrowane.new(szyfr)
    @zasz_ob
  end
end

class Zaszyfrowane
  def initialize(str)
    @napis = str
  end
  def get_str
    @napis
  end
  def odszyfruj(klucz)
    odszyfr=""
    @napis.each_char do |sym|
      klucz.each do |key, value|
        if sym==value
          odszyfr+=key
        end
      end
    end
    odsz_ob=Jawna.new(odszyfr)
    odsz_ob
  end
end

klucz={
    'a' => 'ą',
    'ą'	=> 'b',
    'b'	=> 'c',
    'c'	=> 'ć',
    'ć' => 'd',
    'd' => 'e',
    'e'	=> 'ę',
    'ę'	=> 'f',
   	'f'	=> 'g',
    'g'	=> 'h',
    'h'	=> 'i',
    'i'	=> 'j',
    'j'	=> 'k',
    'k'	=> 'l',
    'l'	=> 'ł',
    'ł'	=> 'm',
    'm'	=> 'n',
    'n'	=> 'ń',
    'ń'	=> 'o',
    'o'	=> 'ó',
    'ó' => 'p',
    'p'	=> 'r',
    'r'	=> 's',
    's'	=> 'ś',
    'ś'	=> 't',
    't'	=> 'u',
    'u'	=> 'w',
    'w'	=> 'y',
    'y'	=> 'z',
    'z'	=> 'ź',
    'ź'	=> 'ż',
    'ż' => 'a'
}

x = Jawna.new("ruby")
print x.get_str,"\n"
print x.zaszyfruj(klucz).get_str,"\n"
print x.zaszyfruj(klucz).odszyfruj(klucz).get_str,"\n"
