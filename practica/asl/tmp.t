function read_chars
  params
    _result
    a
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = a
     readc %6
     %5[i] = %6
     %7 = a
     %8 = %7[i]
     %9 = '.'
     %10 = %8 == %9
     %10 = not %10
     ifFalse %10 goto else1
     %11 = 1
     %12 = i + %11
     i = %12
     goto endif1
  label else1 :
     _result = i
  label endif1 :
     goto beginwhile1
  label endwhile1 :
     %14 = 10
     _result = %14
     return
endfunction

function find_vowels
  params
    n
    vc
    vb
  endparams

  vars
    c 1
  endvars

  label beginwhile1 :
     %1 = 0
     %2 = %1 < n
     ifFalse %2 goto endwhile1
     %3 = 1
     %4 = n - %3
     %5 = vc
     %6 = %5[%4]
     c = %6
     %8 = 1
     %9 = n - %8
     %10 = vb
     %11 = 'a'
     %12 = c == %11
     %13 = 'e'
     %14 = c == %13
     %15 = %12 or %14
     %16 = 'i'
     %17 = c == %16
     %18 = %15 or %17
     %19 = 'o'
     %20 = c == %19
     %21 = %18 or %20
     %22 = 'u'
     %23 = c == %22
     %24 = %21 or %23
     %10[%9] = %24
     %26 = 1
     %27 = n - %26
     n = %27
     goto beginwhile1
  label endwhile1 :
     return
endfunction

function write_consonants
  params
    _result
    n
    vc
    vb
  endparams

  vars
    k 1
    i 1
  endvars

     %1 = 0
     i = %1
     %3 = 0
     %4 = float %3
     k = %4
  label beginwhile1 :
     %5 = i == n
     %5 = not %5
     ifFalse %5 goto endwhile1
     %6 = vb
     %7 = %6[i]
     ifFalse %7 goto else1
     %8 = 1
     %10 = float %8
     %9 = k +. %10
     k = %9
     goto endif1
  label else1 :
     %12 = vc
     %13 = %12[i]
     writec %13
  label endif1 :
     %14 = 1
     %15 = i + %14
     i = %15
     goto beginwhile1
  label endwhile1 :
     %17 = '\n'
     writec %17
     %18 = 100
     %20 = float %18
     %19 = %20 *. k
     %22 = float n
     %21 = %19 /. %22
     _result = %21
     return
endfunction

function main
  vars
    a 10
    b 10
    n 1
    p 1
  endvars

   pushparam 
   %1 = &a
   pushparam %1
   call read_chars
   popparam 
   popparam %2
   n = %2
   pushparam n
   %4 = &a
   pushparam %4
   %5 = &b
   pushparam %5
   call find_vowels
   popparam 
   popparam 
   popparam 
   pushparam 
   pushparam n
   %6 = &a
   pushparam %6
   %7 = &b
   pushparam %7
   call write_consonants
   popparam 
   popparam 
   popparam 
   popparam %8
   p = %8
   writef p
   writes "\n"
   return
endfunction


