SELECT first_name, last_name, city, state
FROM person 
LEFT OUTER JOIN address 
ON person.person_id = address.person_id;
