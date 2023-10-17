PROGRAM DijkstrasAlgorithm(INPUT, OUTPUT);
USES
  Stack;
CONST 
  Operations: SET OF CHAR = ['+', '-', '*', '/', '^'];
  LeftAssociative: SET OF CHAR = ['+', '-', '*', '/'];
  RightAssociative: SET OF CHAR = ['^'];
  Letters: SET OF CHAR = ['a'..'z', 'A'..'Z'];

FUNCTION GetOperationPriority(Operation: CHAR): INTEGER;
VAR
  Priority: INTEGER;
BEGIN
  Priority := 0;
  CASE Operation OF
    '+': Priority := 1; 
    '-': Priority := 1;
    '*': Priority := 2;
    '/': Priority := 2;
    '^': Priority := 3;
  ELSE
    WRITELN('operation read err')
  END;
  GetOperationPriority := Priority 
END;

PROCEDURE OutToLowerPriority(NewOpPriority: INTEGER);
BEGIN
  WHILE((NOT IsStackEmpty()) AND ((GetTop() <> '(') AND (NewOpPriority <= GetOperationPriority(GetTop()))))
  DO
    WRITE(Pop(), ' ')
END;

PROCEDURE OutToLowerAndEqualPriority(NewOpPriority: INTEGER);
BEGIN
  WHILE((NOT IsStackEmpty()) AND ((GetTop() <> '(') AND (NewOpPriority < GetOperationPriority(GetTop()))))
  DO
    WRITE(Pop(), ' ')
END;

PROCEDURE OutToOpenParenthesis();
BEGIN
  WHILE((NOT IsStackEmpty()) AND (GetTop() <> '('))
  DO
    WRITE(Pop(), ' ');
  Pop()
END;

PROCEDURE FullStackOutput();
BEGIN
  WHILE(NOT IsStackEmpty())
  DO
    WRITE(Pop(), ' '); 
END;

VAR
  Ch, OldCh: CHAR;
  NewOpPriority, TopOpPriority: INTEGER;   
BEGIN
  NewOpPriority := 0;
  TopOpPriority := 0;
  OldCh := ' ';
  WHILE NOT EOLN(INPUT)
  DO
    BEGIN
      READ(Ch);
      IF(Ch IN Operations)
      THEN
        BEGIN
          NewOpPriority := GetOperationPriority(Ch);
          IF((NOT IsStackEmpty()) AND (GetTop() IN Operations))
          THEN
            TopOpPriority := GetOperationPriority(GetTop());
             
          IF((IsStackEmpty()) OR ((GetTop() = '(')))
          THEN
            BEGIN
              Push(Ch);
              //WRITELN('1 ', GetTop(), ' ')
            END
          ELSE           
            IF((GetTop() IN Operations) AND (NewOpPriority > TopOpPriority))
            THEN
              BEGIN
                Push(Ch)
              END
            ELSE 
              IF((Ch IN LeftAssociative) AND (GetTop() IN Operations))
              THEN
                BEGIN
                  IF(NewOpPriority <= TopOpPriority)
                  THEN
                    BEGIN
                      OutToLowerPriority(NewOpPriority);
                      Push(Ch)
                    END
                END
              ELSE
                IF((Ch IN RightAssociative) AND (GetTop() IN Operations))
                THEN
                  IF(NewOpPriority < TopOpPriority)
                  THEN
                    BEGIN
                      OutToLowerAndEqualPriority(NewOpPriority);
                      Push(Ch)
                    END
        END
      ELSE
        IF(Ch IN Letters)
        THEN
          BEGIN
            WRITE(Ch, ' ')
          END
        ELSE
          IF(Ch = '(')
          THEN
            Push(Ch)
          ELSE
            IF(Ch = ')')
            THEN
              OutToOpenParenthesis();
      
      IF(((OldCh = '(') OR (OldCh = ' ')) AND (Ch = '-'))
      THEN
        WRITE('0 ');
        
      IF(Ch <> ' ')
      THEN
        OldCh := Ch  
    END;
    FullStackOutput();
    
END.
