int main(void)
{
        struct lwct_state *ls = lwct_init();
        lwct_fatal_assert(ls, 1);
        lwct_show_log(ls);
        lwct_destroy(ls);
}
