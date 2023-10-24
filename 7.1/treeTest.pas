PROGRAM TreeTest(INPUT, OUTPUT);
USES TreeSort;

VAR
  Ch: CHAR;
  
BEGIN
  WHILE NOT EOLN(INPUT)
  DO
    BEGIN
      READ(Ch);
      TreeInsert(Ch)
    END;
  TreePrintSimmetry();
  WRITELN;
  TreePrintStraight();
  WRITELN;
  TreePrintReverse();
END.
  
