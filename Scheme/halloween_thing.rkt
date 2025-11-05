#lang racket

(define name car)

(define Library (list 'library  'book 'chair ))
(define Dungeon (list 'dungeon 'skeleton Library))
(define Cellar  (list 'cellar 'treasure 'rats  Dungeon ))
(define Fridge  (list 'fridge 'sausages 'unidentified_head  ))
(define Kitchen   (list 'kitchen Cellar Fridge))
(define DiningRoom (list 'diningRoom 'table Library Kitchen)  ) 
(define Bathroom  (list 'bathroom 'toilet 'bath 'ghost  Dungeon))
(define Bedroom  (list 'bedroom 'bed Bathroom))
(define Hall  (list  'hall DiningRoom Kitchen Bedroom 'suit_of_armour))
(define House (list 'house Hall))

(define objects
  (lambda(target tree)
    (cond  ( (null? tree)                              '()                         )  
           ( (equal? (car tree) target )                 (cdr(item tree))         )
           ( (not (list? (car tree)))                  (objects target (cdr tree))    )
           ( (null? (objects target (car tree)))            (objects target (cdr tree))  )
           (  #t                (objects target (car tree))   )                                       
)))



(define item
  (lambda (L)
    (cond ( (null? L) '() )
          ( (equal? (list? (car L)) #f) (cons (car L) (item (cdr L)) ) )
          ( #t                           (item (cdr L) )               )
    
    )))
    

          