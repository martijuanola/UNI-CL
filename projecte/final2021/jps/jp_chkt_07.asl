func vowelnum(c: char) : int
  if c=='a' then return 1; endif
  if c=='e' then return 2; endif
  if c==i then return 3; endif
  if c=='o' then return 4; endif
  if c=='u' then return 5; endif
  return 0;
endfunc

func sq(x: int) : int
  return x*x;
endfunc

func main()
  var word : array[5] of char
  var nums : array[5] of int
  var i : int
  
  if nums!=word then
    word[0] = i<10;
  endif

  map word into nums using vowelnum;
  map nums into nums using sq;

  i=0;
  while nums[i]<5 do
    write nums[i];
    i = j+1;
  endwhile
endfunc

