; Delete middle element

(setq linked_list (cons 0 (cons 1 (cons 2 (cons 2 nil)))))

(loop for x in linked_list
  for i from 1 upto (list-length linked_list)
  do (
    if (= i (floor (/ (list-length linked_list) i)))
      (delete i linked_list :count 1 :from-end i)
  ))

(print linked_list)
