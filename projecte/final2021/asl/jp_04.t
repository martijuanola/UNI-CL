function main
  vars
    a 1
    b 1
    x 1
    y 1
  endvars

     %1 = 3
     %2 = float %1
     x = %2
     %3 = 2
     a = %3
     %5 = 6
     b = %5
     %7 = 1
     %8 = 0
     %9 = 1.0
  label beginPower1 :
     %10 = %8 < a
     ifFalse %10 goto endPower1
     %9 = %9 *. x
     %8 = %8 + %7
     goto beginPower1
  label endPower1 :
     y = %9
     %13 = 2
     %15 = float %13
     %14 = y *. %15
     writef %14
     writes "\n"
  label beginwhile4 :
     %16 = 1
     %17 = 0
     %18 = 1.0
  label beginPower2 :
     %19 = %17 < b
     ifFalse %19 goto endPower2
     %18 = %18 *. x
     %17 = %17 + %16
     goto beginPower2
  label endPower2 :
     %21 = 3
     %23 = float %21
     %22 = %23 <. %18
     ifFalse %22 goto endwhile4
     writef x
     writes "**"
     writei b
     writes "="
     %24 = 1
     %25 = 0
     %26 = 1.0
  label beginPower3 :
     %27 = %25 < b
     ifFalse %27 goto endPower3
     %26 = %26 *. x
     %25 = %25 + %24
     goto beginPower3
  label endPower3 :
     writef %26
     writes "\n"
     %29 = 1
     %30 = b - %29
     b = %30
     goto beginwhile4
  label endwhile4 :
     %32 = 3
     %33 = 2.5
     %34 = y -. %33
     %35 = 4
     %36 = b + %35
     %37 = 1
     %38 = 0
     %39 = 1.0
  label beginPower5 :
     %40 = %38 < %36
     ifFalse %40 goto endPower5
     %39 = %39 *. %34
     %38 = %38 + %37
     goto beginPower5
  label endPower5 :
     %43 = float %32
     %42 = %43 +. %39
     %44 = 1
     %45 = b - %44
     %46 = 1
     %47 = 0
     %48 = 1.0
  label beginPower6 :
     %49 = %47 < %45
     ifFalse %49 goto endPower6
     %48 = %48 *. x
     %47 = %47 + %46
     goto beginPower6
  label endPower6 :
     %51 = %42 -. %48
     writef %51
     writes "\n"
     return
endfunction


