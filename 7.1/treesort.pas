UNIT TreeSort;
INTERFACE
  TYPE 
    DataType = CHAR;

  PROCEDURE TreeInsert(Data: DataType);
  PROCEDURE TreePrintSimmetry();
  PROCEDURE TreePrintStraight();
  PROCEDURE TreePrintReverse();
IMPLEMENTATION
TYPE
  NodeTree = ^Tree;
  Tree = RECORD
           Key: DataType;
           Left: NodeTree;
           Right: NodeTree
          END;
  VAR
    Root: NodeTree;
    
    
PROCEDURE Insert(VAR PTR: NodeTree; Data: DataType);
BEGIN
  IF PTR = NIL
  THEN
    BEGIN
      New(PTR);
      PTR^.Key := Data;
      PTR^.Left := NIL;
      PTR^.Right := NIL
    END
  ELSE
    IF PTR^.Key > Data
    THEN
      Insert(PTR^.Left, Data)
    ELSE
      Insert(PTR^.Right, Data)
END;

PROCEDURE TreeInsert(Data: DataType);
BEGIN
  Insert(Root, Data);
  //WRITE(Data)
END;

PROCEDURE PrintSimmetry(PTR: NodeTree);
BEGIN
  IF PTR <> NIL
  THEN
    BEGIN
      PrintSimmetry(PTR^.Left);
      WRITE(PTR^.Key);
      PrintSimmetry(PTR^.Right)
    END
END; 

PROCEDURE TreePrintSimmetry();
BEGIN
  PrintSimmetry(Root)
END; 

PROCEDURE PrintStraight(PTR: NodeTree);
BEGIN
  IF PTR <> NIL
  THEN
    BEGIN
      WRITE(PTR^.Key);
      PrintStraight(PTR^.Left);
      PrintStraight(PTR^.Right)
    END
END; 

PROCEDURE TreePrintStraight();
BEGIN
  PrintStraight(Root)
END; 

PROCEDURE PrintReverse(PTR: NodeTree);
BEGIN
  IF PTR <> NIL
  THEN
    BEGIN
      PrintReverse(PTR^.Left);
      PrintReverse(PTR^.Right);
      WRITE(PTR^.Key)
    END
END; 

PROCEDURE TreePrintReverse();
BEGIN
  PrintReverse(Root)
END; 
      
BEGIN
  Root := NIL;
END.  

