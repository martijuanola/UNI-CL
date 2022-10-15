func islower(a : char) : bool
  return a>='a' and a<='z';
endfunc

func f(x: int) : int
  return x-1;
endfunc

func main()
  var a : array [5] of char
  var b : array [5] of bool
  var c : array [5] of int
  var x : array [10] of char
  var y : array [10] of int
  var z : array [10] of bool
  var n,m : int
  var p,q : char

  while i<y[3] do
     y[3] = y + 1;

     map a into b using islower;
     map x into n using islower;
  endwhile

  if not b[2] or x[0] then
     map p into y using f;
     map n into m using f;
  endif

  map a into z using islower;
  map y into c using f;
  map c into c using f;
endfunc
