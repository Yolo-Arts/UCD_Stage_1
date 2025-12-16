#lang racket

(define sumToN
  (lambda (N L)
    (cond ( #t (+ 2 3) )
          )))

; (sumToN 2 '(1 2) ) will return '(1 2)
; (sumToN 4 '(1 2 2 3)) will return (1 3) (2 2))

(define sum
  (lambda (N L Target)
    (cond ( (null? (cdr L)) (if (equal? N Target) N '()) )
          ( (equal? (- Target (car L)) (car(cdr L)) ) (car L))
          ( #t (sum (car L) (cdr L) (- Target N)) )
          )))

(define test1 '(2 3 4 5))
(define test2 '(1 2 3) )

; (sum (car test1) test1 (- 5 (car test1)))
; (sum (car test1) test1 5)
; (sum (car test2) test2 5)

#|
; What this algorithm is trying to do

; Firstly,
; I want to check if (car L) + (sum (cdr L))
; Will be equal to N
; This means I need a helper function

; I think (sum (cdr L)) needs a second argument.
; Where the second argument will be N - (car L)


; So if we have (sumToN 6 '(1 2 3 4 5))
; The recursive case should be
; (sumToN (N - (car L)) (cdr L))
; This will return: (sumToN 5 '(2 3 4 5))

; Repeat this process until the length of L is 1:
; (sumToN 1 '(5))

; If it is, add N with car L:
; 1 + 5 = 6
; This is equal to 6 which is correct.
; SO what will be the base case?
; (length (car L) 1) (car L)

; and so we need to do
; (+ (N - (car L))(car L))
; and check if it is equal to the N





; I designed a helper function that takes in 3 arguments
; I think I need this to retain the value of 6.
; N (the first item of the list)
; L (the list)
; Target (the number we want to achieve)

; By reducing the list using cdr L, we will get a pattern:
; For example:
; (sum 1 '(1 2 3) 5)
; Should give '(2 3)

; (cdr L) will be '(2 3), where N will be 2.
; I wanted to subtract N from Target:
; 5 - 2
; Compare Target with cdr L:
; (equal? 3 3)
; If this is right, return the numbers.

; Target is reducing to see if the sum of the rest of the list is equal to the target.
; Then we can add the N to that sum and see if this is equal the N of sumToN.

; But my logic is probably flawed


What if i just did a loop like a normal person.
checked if car L + sum of list = 6
and sum of list can be reducing.
so 1 + (sum '2 3 4 5)
and then 2 + (sum '(3 4 5)

THe base case would be if cdr L is '()
then there must be one item in the list.
so we can do 4 + 5
THat is 9 and wrong. So return false or 0.
Then the loop would go back up.
Then 3 + 0 = 3. This would return 3 to
2 + 3 = 5
This would return 5 to
1 + 5 = 6
Therefore we know that (1 2 3) would be an item.
Next we need to check, 1 with (3 4 5)
repeat
Then 1 with (4 5)
then 1 with (5)

But with this method, we would only get (1 2 3) and (1 5)



|#

