#include <pthread.h>

static inline int _pthread_mutex_lock(pthread_mutex_t *mutex, const char *caller, int line)
{
	fprintf(stderr, "%s:%d %s %p\n", caller, line, __func__, mutex);
	int ret = pthread_mutex_lock(mutex);
	fprintf(stderr, "%s:%d %s %p done ret = %d\n", caller, line, __func__, mutex, ret);
	return ret;
}

static inline int _pthread_mutex_unlock(pthread_mutex_t *mutex, const char *caller, int line)
{
	fprintf(stderr, "%s:%d %s %p\n", caller, line, __func__, mutex);
	int ret = pthread_mutex_unlock(mutex);
	fprintf(stderr, "%s:%d %s %p done ret = %d\n", caller, line, __func__, mutex, ret);
	return ret;
}

static inline int _pthread_mutex_trylock(pthread_mutex_t *mutex, const char *caller, int line)
{
	fprintf(stderr, "%s:%d %s %p\n", caller, line, __func__, mutex);
	int ret = pthread_mutex_trylock(mutex);
	fprintf(stderr, "%s:%d %s %p done ret = %d\n", caller, line, __func__, mutex, ret);
	return ret;
}

#define pthread_mutex_lock(x) _pthread_mutex_lock((x), __func__, __LINE__)
#define pthread_mutex_trylock(x) _pthread_mutex_trylock((x), __func__, __LINE__)
#define pthread_mutex_unlock(x) _pthread_mutex_unlock((x), __func__, __LINE__)
