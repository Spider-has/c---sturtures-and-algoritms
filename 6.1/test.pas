PROGRAM Test(INPUT, OUTPUT);
USES
  stack;
  
BEGIN
  Push('+');
  Push('-');
  Push('-');
  WRITELN(GetTop());
  WRITELN(Pop());
  WRITELN(Pop());
  WRITELN(GetTop())
END.
