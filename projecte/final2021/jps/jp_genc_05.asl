func f(r:float, b:bool) : char
  if r > 10 and b then
     return 'R';
  else
     if r< 5 then return '$';
     else return 'k';
     endif
  endif
endfunc

func main()
  var a,b: int
  var x,y: float

  x = 3;
  a = 2;
  b = 6;
  y = a**a;
  write y*2; write "\n";

  while a**b > 3 do
     write a; write "**"; write b; write "=";
     write a**b; write "\n";
     b = b-1;
  endwhile
  write f(3 + 2**(b+4) - x**(b-1), false); write "\n";
endfunc
