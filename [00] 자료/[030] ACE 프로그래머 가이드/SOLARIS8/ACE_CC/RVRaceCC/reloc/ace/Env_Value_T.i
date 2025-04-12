// Env_Value_T.i,v 4.10 2000/04/23 04:42:14 brunsch Exp

template <class T> ACE_INLINE
ACE_Env_Value<T>::operator T (void)
{
  return value_;
}

template <class T> ACE_INLINE
ACE_Env_Value<T>::ACE_Env_Value (void)
  : varname_ (0)
{
}

template <class T> ACE_INLINE
ACE_Env_Value<T>::ACE_Env_Value (const ACE_TCHAR *varname,
                                 const T &defval)
  : varname_ (varname),
    value_(defval)
{
  this->fetch_value ();
}

template <class T> ACE_INLINE void
ACE_Env_Value<T>::open (const ACE_TCHAR *varname,
                        const T &defval)
{
  varname_ = varname;
  value_ = defval;
  this->fetch_value ();
}

template <class T> ACE_INLINE void
ACE_Env_Value<T>::fetch_value (void)
{
// Wide-char environment variables only work on Windows.
#if defined (ACE_WIN32) || !defined (ACE_USES_WCHAR)
  const ACE_TCHAR *env = ACE_OS::getenv (varname_);

  if (env != 0)
    ACE_Convert (env, value_);
#else
  const char *env = ACE_OS::getenv (ACE_TEXT_ALWAYS_CHAR (varname_));

  if (env != 0)
    ACE_Convert (ACE_TEXT_CHAR_TO_TCHAR (env), value_);
#endif /* ACE_WIN32 || !ACE_USES_WCHAR */
}

template <class T> ACE_INLINE const ACE_TCHAR*
ACE_Env_Value<T>::varname (void) const
{
  return varname_;
}

template <class T> ACE_INLINE
ACE_Env_Value<T>::~ACE_Env_Value (void)
{
}
