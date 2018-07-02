#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include "list.h"
#include "convert.h"
#include "menu.h"
#include "function.h"

START_TEST(del_list){
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);
  List_clear1(list);
  List_free(&list);
  ck_assert_ptr_eq(list , NULL);
}
END_TEST


START_TEST (changestruct)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);

  change_struct(list, 0,"profname", "engineer");


  ck_assert_str_eq(get_ProfName(ListNode_data_return(List_head_return(list))), "engineer");
  List_clear(list);
}
END_TEST



START_TEST (change_salary)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);

  
  change_struct(list, 0,"salary", "2125");
 
  ck_assert_int_eq(get_Salary(ListNode_data_return(List_head_return(list))), 2125); 
  List_clear(list); 
}
END_TEST

START_TEST (change_score)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);

  
  change_struct(list, 0,"score", "10.2");
  ck_assert_float_eq(get_Score(ListNode_data_return(List_head_return(list))), 10.2);
  List_clear(list);
}
END_TEST

START_TEST(change_name)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);

  
  change_struct(list, 0,"name", "Andriy");
 
  ck_assert_str_eq(get_Name(ListNode_data_return(List_head_return(list))), "Andriy");
  List_clear(list);
}
END_TEST


START_TEST (change_surname)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);


  change_struct(list, 0,"surname", "Zozula");

  ck_assert_str_eq(get_SurName(ListNode_data_return(List_head_return(list))), "Zozula");
  List_clear(list);
}
END_TEST


START_TEST(change_year){
   List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);

  change_struct(list, 0,"year", "1999");
  ck_assert_int_eq(get_Year(ListNode_data_return(List_head_return(list))), 1999);
  List_clear(list);
}
END_TEST





START_TEST (changestruct_empty_list)
{ 
  List * list = List_new();
  ck_assert_int_eq(change_struct(list, 0,"profname", "engineer"), 1);
  free(list);
}
END_TEST



START_TEST(overwright_struct)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);


  List_overwrite_struct(list ,List_count(list), 1, 0);

  ck_assert_str_eq(get_ProfName(ListNode_data_return(List_head_return(list))), "engineer");
  ck_assert_int_eq(get_Salary(ListNode_data_return(List_head_return(list))), 2000);
  ck_assert_float_eq(get_Score(ListNode_data_return(List_head_return(list))), 8.3);
  ck_assert_str_eq(get_Name(ListNode_data_return(List_head_return(list))), "Sasha");
  ck_assert_str_eq(get_SurName(ListNode_data_return(List_head_return(list))), "Zarichkov");
  ck_assert_int_eq(get_Year(ListNode_data_return(List_head_return(list))), 1998);

  Profecional * test2 = Prof_new();
  overwrite_all_fields(test2, "programist", 2160, 9.2, "Vanya","Savchenko", 1999);
  List_addLast(list, test2);
  List_overwrite_struct(list ,List_count(list), 2,1);

  ck_assert_str_eq(get_ProfName(ListNode_data_return(List_next_return(List_head_return(list)))), "programist");
  ck_assert_int_eq(get_Salary(ListNode_data_return(List_next_return(List_head_return(list)))), 2160);
  ck_assert_float_eq(get_Score(ListNode_data_return(List_next_return(List_head_return(list)))), 9.2);
  ck_assert_str_eq(get_Name(ListNode_data_return(List_next_return(List_head_return(list)))), "Vanya");
  ck_assert_str_eq(get_SurName(ListNode_data_return(List_next_return(List_head_return(list)))), "Savchenko");
  ck_assert_int_eq(get_Year(ListNode_data_return(List_next_return(List_head_return(list)))), 1999);
  List_clear(list);
}
END_TEST



START_TEST(overwright_struct_profname)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);


  List_overwrite_struct(list ,List_count(list), 1, 0);

  ck_assert_str_eq(get_ProfName(ListNode_data_return(List_head_return(list))), "engineer");
  
  List_clear(list);
}
END_TEST





START_TEST(overwright_struct_salary)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);

  List_overwrite_struct(list ,List_count(list), 1, 0);
  ck_assert_int_eq(get_Salary(ListNode_data_return(List_head_return(list))), 2000); 
  List_clear(list);
}
END_TEST


START_TEST(overwright_struct_score)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);


  List_overwrite_struct(list ,List_count(list), 1, 0);

  
  ck_assert_float_eq(get_Score(ListNode_data_return(List_head_return(list))), 8.3);


  
  List_clear(list);
}
END_TEST

START_TEST(overwright_struct_name)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);


  List_overwrite_struct(list ,List_count(list), 1, 0);

  ck_assert_str_eq(get_Name(ListNode_data_return(List_head_return(list))), "Sasha");
  List_clear(list);
}
END_TEST

START_TEST(overwright_struct_surname)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);


  List_overwrite_struct(list ,List_count(list), 1, 0);


  ck_assert_str_eq(get_SurName(ListNode_data_return(List_head_return(list))), "Zarichkov");
  List_clear(list);
}
END_TEST


START_TEST(overwright_struct_year)
{
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);

  List_overwrite_struct(list ,List_count(list), 1, 0);

  ck_assert_int_eq(get_Year(ListNode_data_return(List_head_return(list))), 1998);

  List_clear(list);
}
END_TEST





START_TEST(find_prof){
  List * list = List_new();
  Profecional * test = Prof_new();
  overwrite_all_fields(test, "teacher", 1000, 8.3, "Alla","Zozula", 1971);
  List_addLast(list, test);
  Profecional * test1 = Prof_new();
  overwrite_all_fields(test1, "engineer", 2000, 8.3, "Sasha","Zarichkov", 1998);
  List_addLast(list, test1);
  List * find = List_new();
   find_Profecional(list,find,1001);
  
   ck_assert_str_eq(get_ProfName(ListNode_data_return(List_head_return(find))), "engineer");
   ck_assert_int_eq(get_Salary(ListNode_data_return(List_head_return(find))), 2000);
   ck_assert_float_eq(get_Score(ListNode_data_return(List_head_return(find))), 8.3);
   ck_assert_str_eq(get_Name(ListNode_data_return(List_head_return(find))), "Sasha");
   ck_assert_str_eq(get_SurName(ListNode_data_return(List_head_return(find))), "Zarichkov");
   ck_assert_int_eq(get_Year(ListNode_data_return(List_head_return(find))), 1998);
   List_clear(find);
   List_clear(list);
}
END_TEST



START_TEST(find_prof_emptylist){
  List * list = List_new();
  List * find = List_new();
  find_Profecional(list,find,1001);
  ck_assert_int_eq(find_Profecional(list,find,1001), 1);
   
  free(find);
  free(list);
}
END_TEST


struct Profecional * str_in_struct(char * str, struct Profecional * profs);

START_TEST(strr_in_struct){
  Profecional * test = Prof_new();
  char str[200] = "teacher 1000 8.3 Alla Zozula 1971";
  str_in_struct(str, test);

  ck_assert_str_eq(get_ProfName(test), "teacher");
  ck_assert_int_eq(get_Salary(test), 1000);
  ck_assert_float_eq(get_Score(test), 8.3);
  ck_assert_str_eq(get_Name(test), "Alla");
  ck_assert_str_eq(get_SurName(test), "Zozula");
  ck_assert_int_eq(get_Year(test), 1971);

  Profecional_free(&test);
}
END_TEST




Suite *test_suite() {
  Suite *s = suite_create("Module");

  TCase * tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, changestruct);
  
  TCase * find_profecion = tcase_create("TestCase");
  tcase_add_test(find_profecion, find_prof);
  
  TCase *test_changesruct_emptyl= tcase_create("TestCase");
  tcase_add_test(test_changesruct_emptyl,changestruct_empty_list);
  
  TCase * owerwr_struct = tcase_create("TestCase");
  tcase_add_test(owerwr_struct,overwright_struct);

  TCase * find_prof_empty = tcase_create("TestCase");
  tcase_add_test(find_prof_empty,find_prof_emptylist);

  TCase * str_instruct = tcase_create("TestCase");
  tcase_add_test(str_instruct,strr_in_struct);
  
  TCase * deletete_list = tcase_create("TestCase");
  tcase_add_test(deletete_list,del_list);

  TCase * change_salar = tcase_create("TestCase");
  tcase_add_test(change_salar,change_salary);

  TCase * change_scor = tcase_create("TestCase");
  tcase_add_test(change_scor,change_score);

  TCase * change_nam = tcase_create("TestCase");
  tcase_add_test(change_nam,change_name);

  TCase * change_surnam = tcase_create("TestCase");
  tcase_add_test(change_surnam,change_surname);

  TCase * change_yearr = tcase_create("TestCase");
  tcase_add_test(change_yearr,change_year);

  TCase * overwright_struct_profnam = tcase_create("TestCase");
  tcase_add_test(overwright_struct_profnam,overwright_struct_profname);

  TCase * overwright_struct_salar = tcase_create("TestCase");
  tcase_add_test(overwright_struct_salar,overwright_struct_salary);

  TCase * overwright_struct_scor = tcase_create("TestCase");
  tcase_add_test(overwright_struct_scor,overwright_struct_score);

  TCase * overwright_struct_nam = tcase_create("TestCase");
  tcase_add_test(overwright_struct_nam,overwright_struct_name);
  
  TCase * overwright_struct_surnam = tcase_create("TestCase");
  tcase_add_test(overwright_struct_surnam,overwright_struct_surname);

  TCase * overwright_struct_yearr = tcase_create("TestCase");
  tcase_add_test(overwright_struct_yearr,overwright_struct_year);

  suite_add_tcase(s, overwright_struct_yearr);
  suite_add_tcase(s, overwright_struct_surnam);
  suite_add_tcase(s, overwright_struct_nam);
  suite_add_tcase(s, overwright_struct_scor);
  suite_add_tcase(s, overwright_struct_salar);
  suite_add_tcase(s, overwright_struct_profnam);
  suite_add_tcase(s, change_yearr);
  suite_add_tcase(s, change_surnam);
  suite_add_tcase(s, change_nam);
  suite_add_tcase(s, change_scor);
  suite_add_tcase(s, change_salar);
  suite_add_tcase(s, deletete_list);
  suite_add_tcase(s, str_instruct);
  suite_add_tcase(s, find_prof_empty);
  suite_add_tcase(s, find_profecion);
  suite_add_tcase(s, owerwr_struct);
  suite_add_tcase(s, tc_sample);
  suite_add_tcase(s, test_changesruct_emptyl);
  return s;

}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);  

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;

  
  return 0;
}

