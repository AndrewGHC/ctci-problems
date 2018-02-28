; Print elements in linked list from n

(setq linked_list (cons 0 (cons 1 (cons 2 (cons 2 nil)))))

(let ((n 1))
  (
    loop for n from n upto (list-length linked_list)
        do (print (nth n linked_list))
  )
)
