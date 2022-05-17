function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

     %1 = 5
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     %5 = 88
     %7 = float %5
     %6 = %7 *. f
     %9 = float %4
     %8 = %9 -. %6
     writef %8
     readi %10
     b = %10
     readf %11
     f = %11
     ifFalse b goto endif1
     writes "h\n\tl\\a"
     %12 = -. f
     %13 = -. %12
     %14 = -. %13
     writef %14
     writes "\n"
  label endif1 :
     %15 = 1
     _result = %15
     return
endfunction

function fz
  params
    _result
    r
    u
  endparams

  label beginwhile1 :
     %1 = 0.01
     %3 = float r
     %2 = %1 <. %3
     ifFalse %2 goto endwhile1
     %4 = 1
     %5 = r - %4
     r = %5
     goto beginwhile1
  label endwhile1 :
     %7 = 0
     %8 = r == %7
     ifFalse %8 goto endif1
     %9 = 55555
     pushparam %9
     %10 = 5
     %11 = - %10
     %12 = 4
     %13 = %11 / %12
     %14 = float %13
     pushparam %14
     call f
     popparam 
     popparam 
  label endif1 :
     %15 = 3
     %16 = r + %15
     %18 = float %16
     %17 = %18 *. u
     _result = %17
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 1
   %2 = - %1
   %3 = float %2
   q = %3
   pushparam 
   %4 = 3
   %5 = 4
   %6 = %4 + %5
   pushparam %6
   pushparam 
   %7 = 4444
   pushparam %7
   %8 = 3
   %10 = float %8
   %9 = q +. %10
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %11
   pushparam %11
   call fz
   popparam 
   popparam 
   popparam %12
   q = %12
   writes "\n"
   writef q
   writes "\n"
   %14 = 3.7
   %15 = q +. %14
   %16 = 4
   %18 = float %16
   %17 = %15 +. %18
   writef %17
   writes "\n"
   return
endfunction


