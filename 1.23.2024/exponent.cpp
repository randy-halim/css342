int Pow(int x, int a)
{
  if (a == 0)
  {
    return 1;
  }
  else
  {
    return x * Pow(x, a - 1);
  }
}